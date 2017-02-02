//#ifndef _MY_FUNCTIONS_H_
//#define _MY_FUNCTIONS_H_
//
//#include <string>
//
//// TODO: 20170124  inline: in case of an error of linking.
//inline std::string::size_type findCharacter(const std::string& s, const char& ch,
//    const std::string::size_type& beginPos = 0)
//{
//    if (beginPos != s.npos)
//    {
//        auto pos_Character = beginPos;
//
//        if (beginPos == 0 && s[beginPos] == ch)
//            return 0;
//
//        else
//        {
//            do
//            {
//                pos_Character = s.find(ch, pos_Character + 1);
//            } while (pos_Character != s.npos && s[pos_Character - 1] == '\\');
//
//            return pos_Character;
//        }
//    }
//    else
//        return beginPos;
//}
//
//
//inline std::string deleteLeftRightSpace(const std::string& s)
//{
//    const std::string blankCharList(" \n\r\t");
//
//    std::string s_result(s);
//
//    // 找到左侧非零字符 -> 移动位置，取子串
//    auto pos = s_result.find_first_not_of(blankCharList);
//    if (pos != s_result.npos)
//        s_result = s_result.substr(pos);
//
//    // 找到右侧非零字符 -> 直接取子串
//    pos = s_result.find_last_not_of(blankCharList);
//    if (pos != s_result.npos)
//        s_result = s_result.substr(0, pos + 1);
//
//    return s_result;
//}
//
//inline std::string toUpperCase(const std::string& s)
//{
//    std::string s_result(s);
//
//    // 将 s_result 的每个字符改为大写
//    for (auto& ch : s_result)
//        ch = (char) toupper(ch);
//
//    return s_result;
//}
//
//
//#endif