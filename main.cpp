#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class Directory {
private:
    struct Entry {
        std::string companyName;
        std::string owner;
        std::string phone;
        std::string address;
        std::string activity;
    };

    std::vector<Entry> entries;
    const std::string filename = "directory.txt";

    void loadFromFile() {
        std::ifstream file(filename);
        if (file.is_open()) {
            Entry entry;
            while (file >> entry.companyName >> entry.owner >> entry.phone >> entry.address >> entry.activity) {
                entries.push_back(entry);
            }
            file.close();
        }
    }

    void saveToFile() {
        std::ofstream file(filename);
        if (file.is_open()) {
            for (const auto& entry : entries) {
                file << entry.companyName << " " << entry.owner << " " << entry.phone << " " << entry.address << " " << entry.activity << std::endl;
            }
            file.close();
        }
    }

public:
    Directory() {
        loadFromFile();
    }

    ~Directory() {
        saveToFile();
    }

    void addEntry(const std::string& companyName, const std::string& owner, const std::string& phone, const std::string& address, const std::string& activity) {
        entries.push_back({ companyName, owner, phone, address, activity });
    }

    void searchByCompanyName(const std::string& companyName) const {
        for (const auto& entry : entries) {
            if (entry.companyName == companyName) {
                printEntry(entry);
            }
        }
    }

    void searchByOwner(const std::string& owner) const {
        for (const auto& entry : entries) {
            if (entry.owner == owner) {
                printEntry(entry);
            }
        }
    }

    void searchByPhone(const std::string& phone) const {
        for (const auto& entry : entries) {
            if (entry.phone == phone) {
                printEntry(entry);
            }
        }
    }

    void searchByActivity(const std::string& activity) const {
        for (const auto& entry : entries) {
            if (entry.activity == activity) {
                printEntry(entry);
            }
        }
    }

    void printAllEntries() const {
        for (const auto& entry : entries) {
            printEntry(entry);
        }
    }

private:
    void printEntry(const Entry& entry) const {
        std::cout << "Company Name: " << entry.companyName << std::endl;
        std::cout << "Owner: " << entry.owner << std::endl;
        std::cout << "Phone: " << entry.phone << std::endl;
        std::cout << "Address: " << entry.address << std::endl;
        std::cout << "Activity: " << entry.activity << std::endl;
        std::cout << "------------------------" << std::endl;
    }
};

int main() {
    Directory directory;

    // Add new entries
    directory.addEntry("CompanyA", "OwnerA", "123456789", "AddressA", "ActivityA");
    directory.addEntry("CompanyB", "OwnerB", "987654321", "AddressB", "ActivityB");

    // Search entries
    std::cout << "Search by company name 'CompanyA':" << std::endl;
    directory.searchByCompanyName("CompanyA");

    std::cout << "Search by owner 'OwnerB':" << std::endl;
    directory.searchByOwner("OwnerB");

    // Print all entries
    std::cout << "All entries:" << std::endl;
    directory.printAllEntries();

    return 0;
}
