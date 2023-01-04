#ifndef OBJECT_H_INCLUDED
#define OBJECT_H_INCLUDED

#include <type_traits>
#include <exception>
#include <typeinfo>
#include <iostream>

template<typename C>
class Object {

    protected:

        uintptr_t ptr;

        C content;
        bool isContentDefined;

    public:

        Object() : isContentDefined(false) { }
        Object(C _content) : ptr(reinterpret_cast<uintptr_t>(this)), content(_content), isContentDefined(true) { }

        template<typename CC>
        Object cast(CC obj) {

            if (std::is_same<decltype(content), decltype(obj)>::value && isContentDefined) {

                try {

                    content = obj;
                } catch (std::exception& e) {

                    std::cerr << "Exception : " << e.what() << std::endl;
                }
            }

            return obj;
        }

        bool equals(C first, C second) {

            try {

                if (first.content == second.content) return true;
                else return false;
            } catch (std::exception& e) {

                std::cerr << "Exception : " << e.what() << std::endl;
            }
        }

        uintptr_t getPtr() { return ptr; }
        C getContent() { if (isContentDefined) return content; else return (C) nullptr; }
        void deleteContent() { content = (C) nullptr; }
};

#endif // OBJECT_H_INCLUDED
