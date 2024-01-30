#include <core/project.h>

WINDOW(MyWindow) {
public:
    void Initialize() override {

    }

    void Frame() override {
        
    }
};

int main(int argc, char **argv) {
    ProjectExecutor::Execute(new MyWindow);
}