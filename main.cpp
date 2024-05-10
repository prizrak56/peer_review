#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class ReadingManager {
    const int max_users_ = 100000;
    const int max_page_ = 1000;
public:
    ReadingManager() : users_page_(max_users_ + 1, -1), page_readed_users_(max_page_ + 1, 0) {}

    void Read(int user_id, int page_count) {
        for (int i = users_page_[user_id] + 1; i < page_count + 1; ++i) {
            ++page_readed_users_[i];
        }
        users_page_[user_id] = page_count;
    }

    double Cheer(int user_id) const {
        const int pages_count = users_page_[user_id];
        if (pages_count == -1) {
            return 0;
        }
        const int user_count = page_readed_users_[0];
        if (user_count == 1) {
            return 1;
        }
        return static_cast<double>((static_cast<double>(user_count) - static_cast<double>(page_readed_users_[pages_count])) / static_cast<double>((user_count - 1)));
    }

private:
    vector<int> users_page_;
    vector<int> page_readed_users_;
};

int main() {

    ReadingManager manager;

    int request_count;
    cin >> request_count;

    for (size_t i = 0; i < request_count; i++) {
        string command;
        cin >> command;
        int user_id;
        cin >> user_id;

        if (command == "READ"s) {
            int page_count;
            cin >> page_count;
            manager.Read(user_id, page_count);
        }
        else if (command == "CHEER"s) {
            cout << setprecision(6) << manager.Cheer(user_id) << endl;
        }
    }
}