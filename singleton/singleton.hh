//
// Created by axcens on 02/03/23.
//

#pragma once

#include <cassert>
#include <iostream>
#include <memory>
#include <string>

template <class T>
class Singleton
{
protected:
    Singleton() = default;
    ~Singleton() = default;
    Singleton(const Singleton&) = delete;
    Singleton& operator=(Singleton) = delete;
};

class Logger : public Singleton<Logger>
{
private:
    Logger() = default;
    ~Logger() = default;
    Logger(const Logger&) = delete;
    Logger& operator=(Logger) = delete;

public:
    static Logger* instance()
    {
        static Logger logger;
        return &logger;
    }

    void open_log_file(const std::string& file);
    void write_to_log_file();
    void close_log_file();
};