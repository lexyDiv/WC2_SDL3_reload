#include "../api/out.h"

template <typename T>
class FS
{
public:
    bool write(string path, T item, size_t size);

    Array<T> read(string path, size_t size);
    T reed2(string path, size_t size);

private:
};


template <typename T>
inline bool FS<T>::write(string path, T item, size_t size)
{
        bool isOk;
    ofstream fout;
    fout.open(path, ofstream::app);
    if (fout.is_open())
    {
        fout.write((char *)item, size);
        isOk = true;
        console.log("write ok");
    }
    else
    {
        console.log("trash!!!");
        isOk = false;
    }
    fout.close();
    return isOk;
}

template <typename T>
inline T FS<T>::reed2(string path, size_t size)
{
       T item;
    ifstream fin;
    fin.open(path);
    if (fin.is_open())
    {
        
        fin.read((char *)&item, size);

    }
    fin.close();
    return item;
}

////////////////////////////////////////////////

struct StrData
{
   string str;
};

void writeStr(string *path, string str)
{

            // поток для записи
     // открываем файл для записи
    std::ofstream out(*path, std::ios::app);
    if (out.is_open())
    {
        out << str << std::endl;
    }
    out.close(); 
   // std::cout << "File has been written" << std::endl;

}

void mapWrite(string *path, vector<string> vec)
{
   for (int i = 0; i < vec.size(); i++) {
      string str = vec[i];
      writeStr(path, str);
   }
};

Array<string> readMap(string* path)
{
    std::string line;
    Array<string> arr;
    std::ifstream in(*path); // окрываем файл для чтения
    if (in.is_open())
    {

        while (std::getline(in, line))
        {
           // std::cout << line << std::endl;
           arr.push(line);
        }
    }
    in.close();     // закрываем файл
    return arr;
}