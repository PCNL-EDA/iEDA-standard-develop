/**
 * @file        Resources.hpp
 * @brief       
 * @author      liangyy (jerry9055@163.com)
 * @date        2021-09-06
 * @copyright   Copyright (c) 2021 PLAN-DROP_3th
 */

#include <assert.h>
#include "DirectedGraph.hpp"
#include "Person.hpp"

#ifndef __RESOURCES_HPP_
#define __RESOURCES_HPP_

/**
 * @brief       
 * specify file(s) that need to parse
 * @exception   
 */
enum class K_RESOURCE_TYPE {
    k_people,
    k_relation,
};

/**
 * @brief       
 * A tool class to parse files in resourse directory.
 * 
 * I try to use "factory mode" but it does not exist 
 * inherited relation somewhat.
 * @exception   
 */
class Resources {
    private:
        Resources() = default;   // a tool may not need instance
        // file parser
        static void parsePeopleTxt(std::vector<Person>&);
        static void parseRelationshipTxt(DirectedGraph&);
    public:
        template<typename T>
        static void parseResource(K_RESOURCE_TYPE, T&);
};

/**
 * @brief       The only one interface offered 
 * 
 * @param       type to specify file(s) that need to parse
 * @param       container to store data parsed
 * @exception   
 */
template<typename T>
void Resources::parseResource(K_RESOURCE_TYPE type, T& container) {
    switch (type)
    {
        case K_RESOURCE_TYPE::k_people: {
            assert(typeid(T) == typeid(std::vector<Person>));
            parsePeopleTxt(reinterpret_cast<std::vector<Person>&>(container));
        } break;
        case K_RESOURCE_TYPE::k_relation:{
            assert(typeid(T) == typeid(DirectedGraph));
            parseRelationshipTxt(reinterpret_cast<DirectedGraph&>(container));
        } break;   
        default: assert(0);
    }
}



#endif // __RESOURCES_HPP_