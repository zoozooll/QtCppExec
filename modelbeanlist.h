#ifndef MODELBEANLIST_H
#define MODELBEANLIST_H

#include <vector>
#include <string>

#include <nlohmann/json.hpp>

typedef struct ModelBean {
    std::string name;
    std::string img_path;
    std::string extension;
    std::string enter_filePath;
    std::string ori_config_file_path;
    int version = 0;
    int originate = 0;

    friend void to_json(nlohmann::json& j, const ModelBean& p)
    {
        j = nlohmann::json {
            {"name", p.name},
            {"img_path", p.img_path},
            {"extension", p.extension},
            {"enter_filePath", p.enter_filePath},
            {"ori_config_file_path", p.ori_config_file_path},
            {"version", p.version},
            {"originate", p.originate}
        };
    }

    friend void from_json(const nlohmann::json& j, ModelBean& p)
    {
        j.at("name").get_to(p.name);
        j.at("img_path").get_to(p.img_path);
        j.at("extension").get_to(p.extension);
        j.at("enter_filePath").get_to(p.enter_filePath);
        j.at("ori_config_file_path").get_to(p.ori_config_file_path);
        j.at("version").get_to(p.version);
        j.at("originate").get_to(p.originate);
    }

} ModelBean;

typedef struct ModelBeanList
{
    int version = 0;

    std::vector<ModelBean> model_beans;

    friend void to_json(nlohmann::json& j, const ModelBeanList& p)
    {
        j = nlohmann::json{
            {"version", p.version},
            {"model_beans", p.model_beans}
        };
    }

    friend void from_json(const nlohmann::json& j, ModelBeanList& p)
    {
        j.at("version").get_to(p.version);
        j.at("model_beans").get_to(p.model_beans);
    }
} ModelBeanList;


#endif // MODELBEANLIST_H
