#include "ciutils/ciutils.hh"

#include <iostream>
#include <string>
#include <vector>
#include <yaml-cpp/yaml.h>

namespace CIUtils
{

    CIData parse_ci_file(const std::string& filename)
    {
        CIData data;

        YAML::Node config = YAML::LoadFile(filename);
        data.stages = config["stages"].as<std::vector<std::string>>();

        for (const auto& node : config)
        {
            // For each node in config, parse the stage and scripts using the
            // job name as first key.
            auto job = node.first.as<std::string>();

            // Skip the "stages" job as it is a special gitlab yaml node that we
            // have previously parsed.
            if (job == "stages")
                continue;

            // Retrieves the stage field of the job key.
            auto stage = config[job]["stage"];

            // FIXME: Create the job struct and set the name, stage, and scripts
            // variables accordingly

            Job new_job = { .name = job, .stage = stage.Scalar() };

            data.jobs.push_back(new_job);
            if (std::find(data.stages.begin(), data.stages.end(),
                          stage.Scalar())
                == data.stages.end())
                data.stages.push_back(stage.Scalar());

            auto script = config[job]["script"];
            for (auto elt : script)
            {
                std::stringstream ss(elt.Scalar());
                std::string word;
                getline(ss, word, ' ');
                if (std::find(data.commands.begin(), data.commands.end(), word)
                    == data.commands.end())
                    data.commands.insert(word);
            }
        }

        return data;
    }
} // namespace CIUtils
