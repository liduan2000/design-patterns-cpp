#include <iostream>
#include <string>
#include <vector>

class Logger {
  public:
    Logger(Logger const&) = delete;
    Logger& operator=(Logger const&) = delete;

    static Logger& getInstance() {
        static Logger instance;
        return instance;
    }

    void printLogs() {
        std::cout << "printing logs:" << std::endl;
        for (auto& log : logs_) { std::cout << log << std::endl; }
    }

    void addLog(std::string s) { logs_.emplace_back(s); }

  private:
    Logger() { std::cout << "Logger created" << std::endl; }

    ~Logger() { std::cout << "Logger destroyed" << std::endl; }

    std::vector<std::string> logs_;
};

int main() {
    Logger::getInstance().addLog("hello, log 1");
    Logger::getInstance().addLog("hello, log 2");
    Logger::getInstance().printLogs();
    return 0;
}