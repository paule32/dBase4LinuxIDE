#ifndef BINREADER_H
#define BINREADER_H

class binreader : public std::ifstream
{
public:
	const std::string m_Path;
 
    binreader() : std::ifstream(), m_Path("") { }
    binreader(const
        std::string& path,
        std::ios_base::openmode attr =
        std::ios::binary) :
        std::ifstream(path, (attr |
        std::ios::binary)), m_Path(path)
    { }
 
    template<typename T>
    binreader& operator >> (T& m) {
        read(reinterpret_cast<char*>(&m), sizeof(m));
        return *this;
    }
};

class MyHeaderReader {
public:
    MyHeaderReader(std::string n);

    uint64_t codebeg = 0;
    uint64_t codelen = 0;

    uint8_t * image;
    binreader rd;

    void read_header ();
    void read_library();
    void read_exports();
    void read_image  ();
    
    void call(std::string);
    std::string m_path;
};

class MyCodeRunner {
    std::string lib_name;
public:
    MyCodeRunner(std::string name): lib_name(name) { }
    int     call(std::string fun );
};

#endif
