#include <iostream>
#include <string>
#include <stdexcept>

using std::cout;

const int BAD_ARG_ID = 42;
const std::string BAD_ARG_STR = "42";

class Printer
{
public:
    Printer()
    {
        PrintCall(__FUNCTION__);
    }

    Printer(int id): id_(id)
    {
        PrintCall(__FUNCTION__);

        if (id == BAD_ARG_ID) {
            throw std::invalid_argument("Bad arg id");
        }
    }

    Printer(const std::string& s): Printer(23)
    {
        cout << "Printer[" << id_ << "]::"
             << __FUNCTION__ << "(" << s << ")\n";

        if (s == BAD_ARG_STR) {
            throw std::invalid_argument("Bad arg string");
        }
    }

    ~Printer()
    {
        PrintCall(__FUNCTION__);
    }

private:
    int id_ {};

    void PrintCall(const char* func) {
        cout << "Printer[" << id_ << "]::" << func << '\n';
    }
};

int main()
{
    {
        Printer a;
    }

    try
    {
        // exception at constructor -
        // destructor will not be called
        Printer b(BAD_ARG_ID);
    }
    catch (const std::exception& e)
    {
        cout << "Exception: " << e.what() << '\n';
    }

    try
    {
        // exception at constructor, but desctructor is called
        // because of using delegating constructor
        Printer c(BAD_ARG_STR);
    }
    catch (const std::exception& e)
    {
        cout << "Exception: " << e.what() << '\n';
    }

    return 0;
}
