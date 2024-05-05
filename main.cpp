/*
 * Copyright (c) 2023 ivfzhou
 * ipasigner is licensed under Mulan PSL v2.
 * You can use this software according to the terms and conditions of the Mulan PSL v2.
 * You may obtain a copy of Mulan PSL v2 at:
 *          http://license.coscl.org.cn/MulanPSL2
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
 * EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
 * MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
 * See the Mulan PSL v2 for more details.
 */

#include <iostream>

#include <argparse/argparse.hpp>

int main(int argv, char *argc[]) {
    argparse::ArgumentParser argParser(
        "ipasigner",
        std::string("v").append(VERSION).append("+").append(BUILT_TIME));
    argParser.add_argument("-c", "--config").help("yaml format sign config").default_value("config.yml").required();
    try {
        argParser.parse_args(argv, argc);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        std::cerr << argParser << std::endl;
        return 1;
    }
    auto cfg = argParser.get<std::string>("--config");
    std::cout << cfg << std::endl;

    return 0;
}
