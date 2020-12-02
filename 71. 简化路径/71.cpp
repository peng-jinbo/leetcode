class Solution {
public:
    string simplifyPath(string path) {
        stringstream input_s(path);
        vector<string> strs;
        string temp = "";
        string result = "";
        while(getline(input_s, temp, '/'))
        {
            if(temp == "" || temp == ".") continue;
            else if(temp == ".." && !strs.empty()) strs.pop_back();
            else if(temp != "..") strs.push_back(temp);
        }
        for(auto str:strs) result += '/' + str;
        if(result == "") result += '/';
        return result;
    }
};

// python
// class Solution(object):
//     def simplifyPath(self, path):
//         """
//         :type path: str
//         :rtype: str
//         """
//         input_s = path.split('/')
//         strs = []
//         for str_s in input_s:
//             if str_s == '.' or str_s == '':
//                 continue
//             elif str_s == '..' and len(strs) != 0:
//                 strs.pop()
//             elif str_s != '..':
//                 strs.append(str_s)
//         result = ''
//         for item in strs:
//             result = result + '/' + item
//         if result == '':
//             result += '/'
//         return result