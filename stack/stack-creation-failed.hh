//
// Created by axcens on 02/03/23.
//

#include <stdexcept>
#include <string>

class StackCreationFailed : public std::exception
{
public:
    StackCreationFailed();
    const char * what() const noexcept override;
private:
    std::string msg_;
};