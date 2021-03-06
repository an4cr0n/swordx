#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdbool.h>
#include "utils.h"

void check_heap(void *obj) {
    if(obj == NULL) {
        perror("Out of memory");
        exit(EXIT_FAILURE);
    }
}

fileType type_of_file(char * path) {
    struct stat statbuf;
    if (stat(path, &statbuf) != 0)
       return ERROR_TYPE;
    
    if(S_ISDIR(statbuf.st_mode)) return DIRECTORY;
    if(S_ISREG(statbuf.st_mode)) return REGULAR_FILE;
    return OTHER;
}


bool isSymlink(char * path) {
    struct stat statbuf;
    if (lstat(path, &statbuf) != 0)
        return false;
    
    return S_ISLNK(statbuf.st_mode) ? true : false;
}

void print_logo(void) {
    printf("\n");
    printf(" n                                                                  :.\n");
    printf(" E%%                                                                :\"5\n");
    printf("z  %%                                                              :\" `\n");
    printf("K   \":                                                           z   R\n");
    printf("?     %%.                                                       :^    J\n");
    printf(" \".    ^s                                                     f     :~\n");
    printf("  '+.    #L                                                 z\"    .*\n");
    printf("    '+     %%L                                             z\"    .~\n");
    printf("      \":    '%%.                                         .#     +\n");
    printf("        \":    ^%%.                                     .#`    +\"\n");
    printf("          #:    \"n                                  .+`   .z\"\n");
    printf("            #:    \":                               z`    +\"\n");
    printf("              %%:   `*L                           z\"    z\"\n");
    printf("                *:   ^*L                       z*   .+\"\n");
    printf("                  \"s   ^*L                   z#   .*\"\n");
    printf("                    #s   ^%%L               z#   .*\"\n");
    printf("                      #s   ^%%L           z#   .r\"\n");
    printf("                        #s   ^%%.       u#   .r\"\n");
    printf("                          #i   '%%.   u#   .@\"\n");
    printf("                            #s   ^%%u#   .@\"\n");
    printf("                              #s x#   .*\"\n");
    printf("                               x#`  .@%%.\n");
    printf("                             x#`  .d\"  \"%%.\n");
    printf("                           xf~  .r\" #s   \"%%.\n");
    printf("                     u   x*`  .r\"     #s   \"%%.  x.\n");
    printf("                     %%Mu*`  x*\"         #m.  \"%%zX\n");
    printf("                     :R(h x*              \"h..*dN.\n");
    printf("                   u@NM5e#>                 7?dMRMh.\n");
    printf("                 z$@M@$#\"#\"                 *\"\"*@MM$hL\n");
    printf("               u@@MM8*                          \"*$M@Mh.\n");
    printf("             z$RRM8F\"                             \"N8@M$bL\n");
    printf("            5`RM$#                                  'R88f)R\n");
    printf("            'h.$\"                                     #$x*\n\n\n");
}


void print_pirate_logo(void) {
    printf("\n");
    printf("                                .xm*f""??T?@hc.\n");
    printf("                          z@\"` '~((!!!!!!!?*m.\n");
    printf("                        z$$$K   ~~(/!!!!!!!!!Mh\n");
    printf("                      .f` \"#$k'`~~\\!!!!!!!!!!!MMc\n");
    printf("                     :\"     f*! ~:~(!!!!!!!!!!XHMk\n");
    printf("                     f      \" %%n:~(!!!!!!!!!!!HMMM.\n");
    printf("                    d          X~!~(!!!!!!!X!X!SMMR\n");
    printf("                    M :   x::  :~~!>!!!!!!MNWXMMM@R\n");
    printf(" n                  E ' *  ueeeeiu(!!XUWWWWWXMRHMMM>                :.\n");
    printf(" E%%                 E  8 .$$$$$$$$K!!$$$$$$$$&M$RMM>               :\"5\n");
    printf("z  %%                3  $ 4$$$$$$$$!~!*$$$$$$$$!$MM$               :\" `\n");
    printf("K   \":              ?> # '#$$$$$#~!!!!TR$$$$$R?@MME              z   R\n");
    printf("?     %%.             5     ^\"\"\"~~~:XW!!!!T?T!XSMMM~            :^    J\n");
    printf(" \".    ^s             ?.       ~~d$X$NX!!!!!!M!MM             f     :~\n");
    printf("  '+.    #L            *c:.    .~\"?!!?!!!!!XX@M@~           z\"    .*\n");
    printf("    '+     %%L           #c`\"!+~~~!/!!!!!!@*TM8M           z\"    .~\n");
    printf("      \":    '%%.         'C*X  .!~!~!!!!!X!!!@RF         .#     +\n");
    printf("        \":    ^%%.        9-MX!X!!X~H!!M!N!X$MM        .#`    +\"\n");
    printf("          #:    \"n       'L'!~M~)H!M!XX!$!XMXF      .+`   .z\"\n");
    printf("            #:    \":      R *H$@@$H$*@$@$@$%%M~     z`    +\"\n");
    printf("              %%:   `*L    'k' M!~M~X!!$!@H!tF    z\"    z\"\n");
    printf("                *:   ^*L   \"k ~~~!~!!!!!M!X*   z*   .+\"\n");
    printf("                  \"s   ^*L  '%%:.~~~:!!!!XH\"  z#   .*\"\n");
    printf("                    #s   ^%%L  ^\"#4@UU@##\"  z#   .*\"\n");
    printf("                      #s   ^%%L           z#   .r\"\n");
    printf("                        #s   ^%%.       u#   .r\"\n");
    printf("                          #i   '%%.   u#   .@\"\n");
    printf("                            #s   ^%%u#   .@\"\n");
    printf("                              #s x#   .*\"\n");
    printf("                               x#`  .@%%.\n");
    printf("                             x#`  .d\"  \"%%.\n");
    printf("                           xf~  .r\" #s   \"%%.\n");
    printf("                     u   x*`  .r\"     #s   \"%%.  x.\n");
    printf("                     %%Mu*`  x*\"         #m.  \"%%zX\n");
    printf("                     :R(h x*              \"h..*dN.\n");
    printf("                   u@NM5e#>                 7?dMRMh.\n");
    printf("                 z$@M@$#\"#\"                 *\"\"*@MM$hL\n");
    printf("               u@@MM8*                          \"*$M@Mh.\n");
    printf("             z$RRM8F\"                             \"N8@M$bL\n");
    printf("            5`RM$#                                  'R88f)R\n");
    printf("            'h.$\"                                     #$x*\n\n\n");
}