/* Case report code: you do not need to read or modify this file :)
 *
 * The confirmation code is encrypted: it can only be decrypted with a key
 * computed from the correct result of the exercise.
 * The revealed code is bound to the current user and machine.
 */
#include "report.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define FNV_START 2166136261u

static unsigned int mix(unsigned int h, unsigned int v) {
    for (int i = 0; i < 4; i++) {
        h ^= (v >> (8 * i)) & 0xff;
        h *= 16777619u;
    }
    return h;
}

static unsigned int next_byte(unsigned int *s) {
    *s ^= *s << 13;
    *s ^= *s >> 17;
    *s ^= *s << 5;
    return *s & 0xff;
}

/* Decrypts 'len' bytes of 'enc' into 'out' and returns its checksum */
static unsigned int decrypt(unsigned int key, const unsigned char *enc, int len, char *out) {
    unsigned int s = key ? key : 1;
    unsigned int h = FNV_START;
    for (int i = 0; i < len; i++) {
        out[i] = enc[i] ^ next_byte(&s);
        h = mix(h, (unsigned char)out[i]);
    }
    out[len] = '\0';
    return h;
}

/* Appends to 'word' a code bound to the current user and machine */
static void bind_to_user(char *out, size_t size, const char *word) {
    const char *user = getenv("USER");
    char host[256] = "";
    char id[600];

    if (user == NULL || user[0] == '\0')
        user = "unknown";
    if (gethostname(host, sizeof(host)) != 0 || host[0] == '\0')
        strcpy(host, "unknown");
    host[sizeof(host) - 1] = '\0';

    snprintf(id, sizeof(id), "%s:%s@%s", word, user, host);
    unsigned int h = FNV_START;
    for (const char *c = id; *c != '\0'; c++) {
        h ^= (unsigned char)*c;
        h *= 16777619u;
    }
    snprintf(out, size, "%s-%04X", word, h & 0xffff);
}

static void reveal(int number, unsigned int key, const unsigned char *enc, int len, unsigned int check) {
    char word[32];
    char bound[48];
    if (decrypt(key, enc, len, word) != check)
        return;
    bind_to_user(bound, sizeof(bound), word);
    printf("\n*** Case report, code #%d of 5: \"%s\" ***\n", number, bound);
}

#include <fcntl.h>
#include <sys/stat.h>
#include <time.h>

/* The exercise is correct only if:
 *  - homeDir is the HOME of the environment and startDir, the working
 *    directory read before moving, is outside it (the branch was taken
 *    for the right reason);
 *  - the process is now exactly in homeDir (chdir done);
 *  - marker.txt in it is a regular, empty file with mode rw-------,
 *    written in this run (open with O_CREAT | O_WRONLY | O_TRUNC and
 *    S_IRUSR | S_IWUSR);
 *  - the descriptor used to create it was closed (3 is free again).
 */
void report_check(const char *homeDir, const char *startDir) {
    static const unsigned char enc[] = {0x57, 0x4b, 0xec};
    const char *envHome = getenv("HOME");
    char cwd[4096];
    struct stat st;
    int ok = 1;

    if (homeDir == NULL || envHome == NULL || strcmp(homeDir, envHome) != 0)
        ok = 0;
    if (ok && (startDir == NULL || startDir[0] != '/' ||
               strncmp(startDir, homeDir, strlen(homeDir)) == 0))
        ok = 0;
    if (ok && (getcwd(cwd, sizeof(cwd)) == NULL || strcmp(cwd, homeDir) != 0))
        ok = 0;
    if (ok && (stat("marker.txt", &st) == -1 || !S_ISREG(st.st_mode) ||
               st.st_size != 0 || labs((long)(time(NULL) - st.st_mtime)) > 120))
        ok = 0;
    if (ok && (st.st_mode & 0777) != (S_IRUSR | S_IWUSR)) {
        printf("marker.txt has the wrong permissions: remove it and run again\n");
        ok = 0;
    }
    if (ok) {
        int fd = open("marker.txt", O_RDONLY);
        if (fd != 3) /* the descriptor of the exercise is still open */
            ok = 0;
        if (fd != -1)
            close(fd);
    }
    unsigned int key = mix(mix(FNV_START, 0x33), ok);
    reveal(3, key, enc, sizeof(enc), 0x902f531cu);
}
