//
// Created by axcens on 03/03/23.
//

#include <ciutils/ciutils.hh>
#include <iostream>

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        std::cerr << "Usage: cipeek " << '\n';
        return 1;
    }

    const std::string filename(argv[1]);
    CIUtils::CIData data = CIUtils::parse_ci_file(filename);

    // Print stages
    std::cout << "stages(" << data.stages.size() << "):" << '\n';
    for (const auto& stage : data.stages)
    {
        std::cout << "  " << stage << "\n";
    }

    std::cout << "\n";

    // Print jobs
    std::cout << "jobs(" << data.jobs.size() << "):" << '\n';
    for (const auto& job : data.jobs)
    {
        std::cout << "  " << job.name << " (" << job.stage << ")" << '\n';
    }

    std::cout << "\n";

    // Print commands
    std::cout << "commands(" << data.commands.size() << "):" << '\n';
    for (const auto& command : data.commands)
    {
        std::cout << "  " << command << '\n';
    }

    return 0;
}