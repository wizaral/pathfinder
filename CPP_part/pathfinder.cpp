#include "pathfinder.h"

static inline void read_data(Info &info, std::ifstream &file) {
    std::string temp;
    size_t i1 = 0, i2 = 0, current = 0;
    vector<std::string>::iterator it;

    while (!file.eof()) {
        std::getline(file, temp, '-');

        if (temp != "") {
            if ((it = std::find(info.names.begin(), info.names.end(), temp)) == info.names.end()) {
                i1 = current;
                info.names[current++] = std::move(temp);
            }
            else
                i1 = it - info.names.begin();
        }

        std::getline(file, temp, ',');

        if (temp != "") {
            if ((it = std::find(info.names.begin(), info.names.end(), temp)) == info.names.end()) {
                i2 = current;
                info.names[current++] = std::move(temp);
            }
            else
                i2 = it - info.names.begin();
        }

        std::getline(file, temp);
        if (temp != "" && i1 != i2) {
            info.graph[i1].emplace_back(std::make_pair(i2, std::stoi(temp)));
            info.graph[i2].emplace_back(std::make_pair(i1, std::stoi(temp)));
        }
    }
}

void log_print(Info &info) {
    cout << "Size: " << info.size << endl;

    for (size_t i = 0; i < info.size; ++i)
        cout << "Name[" << i << "]: " << info.names[i] << endl;
    for (size_t i = 0; i < info.size; ++i)
        for (const auto &j : info.graph[i])
            cout << "From[" << i << "] to[" << j.first << "]: " << j.second << endl;
}

int main(int argc, char **argv) {
    if (argc == 2) {
        std::ifstream file(argv[1]);
        if (file) {
            std::string num;
            std::getline(file, num);
            Info info(std::stoi(num));
            read_data(info, file);
            file.close();
            // log_print(info);
            algorithm(info);
        }
    }
    else
        cout << "usage: ./pathfinder [filename]" << endl;
}
