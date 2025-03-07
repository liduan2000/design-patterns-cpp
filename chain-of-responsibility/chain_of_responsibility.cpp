#include <iostream>
#include <memory>
#include <string>

enum class LogLevel { INFO, DEBUG, ERROR };

// handler
class Logger {
  public:
    Logger() : nextLogger_(nullptr) {}

    virtual ~Logger() = default;

    void setNextLogger(std::shared_ptr<Logger> nextLogger) { nextLogger_ = nextLogger; }

    virtual void logMessage(LogLevel level, const std::string message) const {
        if (nextLogger_ != nullptr) { nextLogger_->logMessage(level, message); }
    }

  private:
    std::shared_ptr<Logger> nextLogger_;
};

// concrete handler
class InfoLogger : public Logger {
  public:
    void logMessage(LogLevel level, const std::string message) const override {
        if (level == LogLevel::INFO) {
            std::cout << "[INFO] " << message << std::endl;
        } else {
            Logger::logMessage(level, message);
        }
    }
};

// concrete handler
class DebugLogger : public Logger {
  public:
    void logMessage(LogLevel level, const std::string message) const override {
        if (level == LogLevel::DEBUG) {
            std::cout << "[DEBUG] " << message << std::endl;
        } else {
            Logger::logMessage(level, message);
        }
    }
};

// concrete handler
class ErrorLogger : public Logger {
  public:
    void logMessage(LogLevel level, const std::string message) const override {
        if (level == LogLevel::ERROR) {
            std::cout << "[ERROR] " << message << std::endl;
        } else {
            Logger::logMessage(level, message);
        }
    }
};

int main() {
    std::shared_ptr<Logger> infoLogger = std::make_shared<InfoLogger>();
    std::shared_ptr<Logger> debugLogger = std::make_shared<DebugLogger>();
    std::shared_ptr<Logger> errorLogger = std::make_shared<ErrorLogger>();

    infoLogger->setNextLogger(debugLogger);
    debugLogger->setNextLogger(errorLogger);

    infoLogger->logMessage(LogLevel::INFO, "This is an info message.");
    infoLogger->logMessage(LogLevel::DEBUG, "This is a debug message.");
    infoLogger->logMessage(LogLevel::ERROR, "This is an error message.");

    return 0;
}