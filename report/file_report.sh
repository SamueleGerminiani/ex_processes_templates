#!/bin/bash
# The case report: it can be filed only with the 5 confirmation codes
# revealed by the lab programs.
#   Code #1: the demo (redirect_demo, at the end of demo.log)
#   Code #2: Exercise 1 (10 child processes)
#   Code #3: Exercise 2 (the worker terminated with kill)
#   Code #4: Exercise 4 (the multiplier started by the generator)
#   Code #5: Exercise 5 (./process_ese5 ls /nonexistent)
# Codes #2 to #5 are bound to the user and machine that obtained them.

cd "$(dirname "$0")" || exit 1
export LC_ALL=C

# Same code as bind_to_user() in the exercises: FNV-1a of "word:user@host"
code_for() {
    local id="$1:${USER:-unknown}@$(uname -n)"
    local h=2166136261 c i
    for ((i = 0; i < ${#id}; i++)); do
        printf -v c '%d' "'${id:i:1}"
        h=$(( ((h ^ c) * 16777619) & 0xFFFFFFFF ))
    done
    printf '%04X' $(( h & 0xFFFF ))
}

echo "The case is still open: the report needs 5 confirmation codes."
password=""
for i in 1 2 3 4 5; do
    read -r -p "Code #$i: " code
    # Ignore quotes, extra spaces and uppercase letters
    code=$(echo "$code" | tr -d '"' | tr '[:upper:]' '[:lower:]' | xargs)
    word=${code%%-*}
    if [ "$i" -gt 1 ] && [ "$code" != "$word-$(code_for "$word" | tr '[:upper:]' '[:lower:]')" ]; then
        echo "Code #$i was not obtained by you on this machine: the report is rejected."
        exit 1
    fi
    password="$password $word"
done
password=$(echo "$password" | xargs)

report=$(openssl enc -d -aes-256-cbc -pbkdf2 -iter 100000 -a \
    -in case_report.enc -pass "pass:$password" 2>/dev/null)

if [ "$(echo "$report" | head -n 1)" = "REPORT-OK" ]; then
    echo "$report" | tail -n +2
else
    echo "The report is rejected... check your codes (and their order)!"
fi
