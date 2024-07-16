#include "jsonexec.h"

#include <iostream>
#include <fstream>
#include <string>

#include "nlohmann/json.hpp"
#include "modelbeanlist.h"

static void jsonFromString();

static void jsonFromStream();

static void jsonToBean();

static void beanToJson();


void jsonExercise()
{
    jsonFromString();
    jsonFromStream();
    jsonToBean();
    beanToJson();
}


void jsonFromString()
{
    auto json_str = R"(
      {
        "enter_filePath": "coordinate.h3da",
        "extension": "h3da",
        "img_path": "",
        "name": "coordinate",
        "ori_config_file_path": "configs.json",
        "originate": 0,
        "version": 2
    }
    )";

    nlohmann::json ex1 = nlohmann::json::parse(json_str);
}

void jsonFromStream()
{
    std::ifstream f("model_list.json");
    nlohmann::json data = nlohmann::json::parse(f);

    std::cout << data << std::endl;
}

void jsonToBean()
{
    std::ifstream f("model_list.json");
    nlohmann::json data = nlohmann::json::parse(f);
    ModelBeanList new_person = data.get<ModelBeanList>();
}

void beanToJson()
{
    ModelBeanList list;
    list.version = 1;

    ModelBean bean0;
    bean0.name = "bean0";
    bean0.extension = "obj";
    bean0.img_path = "icon.png";
    bean0.enter_filePath = "bean0.obj";
    bean0.ori_config_file_path = "configs.json";
    bean0.originate = 2;
    bean0.version = 1;
    list.model_beans.push_back(bean0);

    ModelBean bean5;
    bean5.name = "bean5";
    bean5.extension = "obj";
    bean5.img_path = "icon.png";
    bean5.enter_filePath = "bean5.obj";
    bean5.ori_config_file_path = "configs.json";
    bean5.originate = 2;
    bean5.version = 1;
    list.model_beans.push_back(bean5);

    ModelBean bean1;
    bean1.name = "bean1";
    bean1.extension = "obj";
    bean1.img_path = "icon.png";
    bean1.enter_filePath = "bean1.obj";
    bean1.ori_config_file_path = "configs.json";
    bean1.originate = 2;
    bean1.version = 1;
    list.model_beans.push_back(bean1);


    ModelBean bean2;
    bean2.name = "bean2";
    bean2.extension = "obj";
    bean2.img_path = "icon.png";
    bean2.enter_filePath = "bean2.obj";
    bean2.ori_config_file_path = "configs.json";
    bean2.originate = 2;
    bean2.version = 1;
    list.model_beans.push_back(bean2);

    ModelBean bean3;
    bean3.name = "bean3";
    bean3.extension = "obj";
    bean3.img_path = "icon.png";
    bean3.enter_filePath = "bean3.obj";
    bean3.ori_config_file_path = "configs.json";
    bean3.originate = 2;
    bean3.version = 1;
    list.model_beans.push_back(bean3);

    ModelBean bean4;
    bean4.name = "bean4";
    bean4.extension = "obj";
    bean4.img_path = "icon.png";
    bean4.enter_filePath = "bean4.obj";
    bean4.ori_config_file_path = "configs.json";
    bean4.originate = 2;
    bean4.version = 1;
    list.model_beans.push_back(bean4);

    nlohmann::json j_bean4 {};
    j_bean4["name"] = bean4.name;
    j_bean4["extension"] = bean4.extension;
    j_bean4["img_path"] = bean4.img_path;
    j_bean4["enter_filePath"] = bean4.enter_filePath;
    j_bean4["ori_config_file_path"] = bean4.ori_config_file_path;
    j_bean4["originate"] = bean4.originate;
    j_bean4["version"] = bean4.version;

    std::cout << "j_bean4: " << j_bean4 << std::endl;


    nlohmann::json j_list = nlohmann::json(list);
    std::cout << "ModelBeanList: " << j_list << std::endl;
}
