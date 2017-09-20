#ifndef TEST_LIBRARY_H
#define TEST_LIBRARY_H



#if defined(TEST_BEGIN)
    #define main main____
    #undef main
    #define ____main main
    int ____main(int argc,char *argv[])
    {
        #if defined(Before)
            Before;
        #endif
        #if defined(Test)
            Test;
        #endif
        #if defined(After)
            After;
        #endif
        return 0;
    }
#endif

#endif

