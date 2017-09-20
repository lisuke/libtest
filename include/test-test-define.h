//
// Created by lisuke on 9/20/17.
//

#ifndef TEST_TEST_DEFINE_H
#define TEST_TEST_DEFINE_H


DEFINE_TEST_FUNC(void,before,);
DEFINE_TEST_FUNC(void,test,);
DEFINE_TEST_FUNC(void,after,);

#define Before before()
#define Test test()
#define After after()




#endif
