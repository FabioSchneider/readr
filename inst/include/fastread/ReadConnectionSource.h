#ifndef FASTREAD_ReadConnectionSource_H
#define FASTREAD_ReadConnectionSource_H

namespace fastread {
        
    class ReadConnectionSource : public Source<ReadConnectionSource>{
    public:
        typedef Source<ReadConnectionSource> Base ;
        
        ReadConnectionSource(SEXP con_d, char sep = ',', char quote = '"', char esc = '\\') ;
        
        bool ensure_full_line(); 
        bool more() ;
        
    private:
        Rconnection con ;
        
        void find_last_line() ;
        
        int chunk_size ;
        std::vector<char> buffer ;
        char* data ;
        char* last_full_line ;
        int n ;
    } ;
}

#endif
