#ifndef BINWRITER_H
#define BINWRITER_H

class binwriter : public std::ofstream
{
public:
	const std::string m_Path;
 
    binwriter() : std::ofstream(), m_Path("") { }
    binwriter(const
        std::string& path,
        std::ios_base::openmode attr =
        std::ios::binary) :
        std::ofstream(path, (attr |
        std::ios::binary)), m_Path(path)
    { }
 
    template<typename T>
    binwriter& operator << (const T& m) {
        static_assert(!std::is_pointer<T>::value, "T must not be a pointer type");
        static_assert(std::is_standard_layout<T>::value, "T must be an standard layout type");
        write(reinterpret_cast<const char*>(&m), sizeof(m));
        return *this;
    }
};

class MyHeaderWriter {
public:
    MyHeaderWriter(
         std::string n,
         uint64_t length,
         void   * buffer);
    ~MyHeaderWriter();
    
    uint64_t codebeg = 0;
    uint64_t codelen = 0;
    
    uint64_t init_header  ();
    uint64_t init_libs    ();
    uint64_t init_exports ();
    uint64_t init_image   (void * buffer);
    
    void write_image  ();
    void write_exports();
    void write_libs   ();
    void write_header ();
    
    void write_data   ();
    
    std::string lib_name;
    std::string out_name;
    
    uint64_t  exports_position = 0;
    uint64_t  code_position    = 0;
    
    char     * header_image;
    uint64_t   header_image_length;
    
    char     * lib_image;
    uint64_t   lib_image_length;
    
    char     * export_image;
    uint64_t   export_image_length;
    
    char     * code_image;
    uint64_t   code_image_length;
    
    binwriter   wr;
    std::string m_path;
};

#endif
