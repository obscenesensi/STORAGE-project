#include <stdio.h>
#include <memory>

int main() {
    std::unique_ptr<FILE, int(*)(FILE*)> fp(fopen("test.txt", "r"), fclose);

    if(fp) {
        char buf[4096];
        while(fgets(buf, sizeof(buf), fp.get())) {
            printf("%s", buf);
        }
    }
}
