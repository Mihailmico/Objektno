#include <iostream>
#include <cstring>
using namespace std;

class Achievement {
private:
    char name[100];
    char description[100];
    static int totalUserAchievements;

    friend class UserProfile;
    friend void showAchievementsProgress(UserProfile profiles[], int n, Achievement achievements[], int m);
public:
    Achievement() { totalUserAchievements++; }
    Achievement(const char *name, const char *description) {
        strncpy(this->name, name, sizeof(this->name) - 1);
        this->name[sizeof(this->name) - 1] = '\0';
        strncpy(this->description, description, sizeof(this->description) - 1);
        this->description[sizeof(this->description) - 1] = '\0';
        totalUserAchievements++;
    }
    Achievement(const Achievement &other) {
        strncpy(this->name, other.name, sizeof(this->name) - 1);
        this->name[sizeof(this->name) - 1] = '\0';
        strncpy(this->description, other.description, sizeof(this->description) - 1);
        this->description[sizeof(this->description) - 1] = '\0';
        totalUserAchievements++;
    }
    ~Achievement() { totalUserAchievements--; }
    void print() {
        cout << name << endl;
        cout << description << endl;
    }
    static void incrementTotalUserAchievements() {
        totalUserAchievements++;
    }
    static int getTotalUserAchievements() {
        return totalUserAchievements;
    }
};

int Achievement::totalUserAchievements = 0;

class UserProfile {
private:
    char name[100];
    Achievement achievements[50];
    int numAchievements;
    friend class Achievement;
    friend void showAchievementsProgress(UserProfile profiles[], int n, Achievement achievements[], int m);

public:
    UserProfile() (){ numAchievements = 0; }
    UserProfile(const char *name) {
        strncpy(this->name, name, sizeof(this->name) - 1);
        this->name[sizeof(this->name) - 1] = '\0';
        numAchievements = 0;
    }
    void print() {
        cout << "User: " << name << endl;
        cout << "Achievements: " << endl;
        for (int i = 0; i < numAchievements; i++) {
            achievements[i].print();
        }
    }
    void addAchievement(const Achievement &achievement) {
        if (numAchievements < 50) {
            achievements[numAchievements++] = achievement;
            achievement.incrementTotalUserAchievements();
        }
    }
    int getNumAchievements() const {
        return numAchievements;
    }
};

void showAchievementsProgress(UserProfile profiles[], int n, Achievement achievements[], int m) {
    for (int i = 0; i < m; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < profiles[j].getNumAchievements(); k++) {
                if (strcmp(profiles[j].achievements[k].name, achievements[i].name) == 0) {
                    count++;
                    break;
                }
            }
        }
        cout << achievements[i].name << endl;
        cout << achievements[i].description << endl;
        cout << "Unlocked by: " << (count * 100.0 / n) << "% of users" << endl;
    }
    double avgAchievements = (Achievement::getTotalUserAchievements() * 100.0) / (n * m);
    cout << "Average achievements unlocked: " << avgAchievements << "%" << endl;
}

int main() {
    char testcase[100];
    cin.getline(testcase, 100);

    int n;
    cin >> n;
    cin.ignore();

    char ignore[100];
    cin.getline(ignore, 100);
    UserProfile users[100];
    for (int i = 0; i < n; ++i) {
        char name[100];
        cin >> name;
        users[i] = UserProfile(name);
    }

    int m;
    cin >> m;
    cin.ignore();

    cin.getline(ignore, 100);
    Achievement achievements[100];
    for (int i = 0; i < m; ++i) {
        char name[100], description[100];
        cin.getline(name, 100);
        cin.getline(description, 100);
        achievements[i] = Achievement(name, description);
    }

    int k;
    cin >> k;
    cin.ignore();

    cin.getline(ignore, 100);
    for (int i = 0; i < k; ++i) {
        int numUser, numAchievement;
        cin >> numUser >> numAchievement;
        numUser -= 1;
        numAchievement -= 1;
        users[numUser].addAchievement(achievements[numAchievement]);
    }

    if (testcase[8] == 'A') {  // Testing Achievement methods.
        for (int i = 0; i < m; ++i) {
            achievements[i].print();
        }
        Achievement::incrementTotalUserAchievements();
    } else if (testcase[8] == 'U') {  // Testing UserProfile methods.
        for (int i = 0; i < n; ++i) {
            users[i].print();
        }
    } else {  // Testing showAchievementsProgress function.
        showAchievementsProgress(users, n, achievements, m);
    }

    return 0;
}