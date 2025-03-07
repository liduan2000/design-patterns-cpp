#include <iostream>
#include <memory>
#include <string>
#include <vector>

// abstract component
class FileSystemComponent {
  public:
    virtual ~FileSystemComponent() = default;
    virtual void display(int indent = 0) const = 0;
};

// leaf class
class File : public FileSystemComponent {
  public:
    explicit File(const std::string& name) : name_(name) {}

    void display(int indent = 0) const override { std::cout << std::string(indent, ' ') << "- " << name_ << std::endl; }

  private:
    std::string name_;
};

// composite class
class Folder : public FileSystemComponent {
  public:
    explicit Folder(const std::string& name) : name_(name) {}

    void display(int indent = 0) const override {
        std::cout << std::string(indent, ' ') << "+ " << name_ << std::endl;
        for (const auto& child : children_) { child->display(indent + 2); }
    }

    void add(const std::shared_ptr<FileSystemComponent>& component) { children_.push_back(component); }

  private:
    std::string name_;
    std::vector<std::shared_ptr<FileSystemComponent>> children_;
};

int main() {
    std::shared_ptr<File> file1 = std::make_shared<File>("file1.txt");
    std::shared_ptr<File> file2 = std::make_shared<File>("file2.txt");
    std::shared_ptr<File> file3 = std::make_shared<File>("file3.txt");

    std::shared_ptr<Folder> folder1 = std::make_shared<Folder>("Folder1");
    folder1->add(file1);
    folder1->add(file2);

    std::shared_ptr<Folder> rootFolder = std::make_shared<Folder>("RootFolder");
    rootFolder->add(folder1);
    rootFolder->add(file3);

    rootFolder->display();

    return 0;
}