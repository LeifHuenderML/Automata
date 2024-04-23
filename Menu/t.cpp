#include <iostream>
#include <unistd.h>

int main(){
char cwd[1024];
if (getcwd(cwd, sizeof(cwd)) != nullptr) {
    std::cout << "Current working dir: " << cwd << std::endl;
} else {
    perror("getcwd() error");
}
}