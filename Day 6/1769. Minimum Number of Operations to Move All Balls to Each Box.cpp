class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> count;
        count.push_back(
            boxes[0] == '1' ? 1 : 0
        );
        
        vector<int> answer;
        answer.push_back(0);
        for (int i=1; i<boxes.size(); i++) {
            if(boxes[i] == '1') {
                count.push_back(count.back() + 1);
                answer[0] += i;
            }
            else {
                count.push_back(count.back());
            }
        }
        
        for (int i=1; i<boxes.size(); i++) {
            
            answer.push_back(0);
            answer[i] += 2*count[i-1];
            answer[i] += answer[i-1];
            answer[i] -= count.back();
            
        }
        
        return answer;
    }
};