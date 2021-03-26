#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char strInputLink[BUFSIZ];
    char inputReadme[BUFSIZ];
    char strLinkReadme[BUFSIZ];
    int contStrLinkReadme = 0;
    int contLink = 0;
    int numberOfLinks = 0;

    FILE *links = fopen("links.txt", "r");
    if (!links)
        return 1;

    char c;
    while(fread (&c, sizeof(char), 1, links)) {
        if(c == '\n') {
            numberOfLinks++;
        }
    }

    rewind(links);

    FILE *README = fopen("README.md", "r");

    while(!feof(README)) {
        fgets(inputReadme, BUFSIZ, README);
        if (inputReadme[2] == '`')
            continue;

        size_t beforeLink;
        for (beforeLink = 0; beforeLink < sizeof(inputReadme); beforeLink++)
            if (inputReadme[beforeLink] == '(')
                break;
        beforeLink++;

        for (size_t i = 0; i < sizeof(inputReadme); i++) {
            if (inputReadme[beforeLink + i] == ')')
                break;
            strLinkReadme[i] = inputReadme[beforeLink + i];
        }
    }

    fclose(README);

    while(!feof(links)) {
        fgets(strInputLink, BUFSIZ, links);
        contStrLinkReadme++;
        if (strcmp(strLinkReadme, strInputLink) == 0)
            break;
    }

    printf("old (%d): %s\n", contStrLinkReadme, strLinkReadme);

    rewind(links);

    while(!feof(links)) {
        fgets(strInputLink, BUFSIZ, links);
        contLink++;
        if (contLink == (numberOfLinks + 1)) {
            rewind(links);
            contStrLinkReadme = 0;
            contLink = 0;
        }
        if (contLink > contStrLinkReadme)
            break;
    }

    README = fopen("README.md", "w");
    fprintf(README, "``` hello, welcome to my github ```\n");
    fprintf(README, "![%d](%s)", contLink, strInputLink);

    printf("new (%d): %s", contLink, strInputLink);

    fclose(links);
    fclose(README);
    return 0;
}
