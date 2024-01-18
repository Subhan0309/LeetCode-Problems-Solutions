class Solution:
    def closeStrings(self, word1: str, word2: str) -> bool:

        map_1 = dict()
        map_2 = dict()

        if len(word1) != len(word2):
            return False
        
        for i in word1:
            if i in map_1:
                map_1[i] += 1
            else:
                map_1[i] = 1

        for i in word2:
            if i in map_2:
                map_2[i] += 1
            else:
                map_2[i] = 1
        if(len(map_1) != len(map_2)):
            return False

        sorted_map_1 = sorted(map_1.items(), key=lambda x:x[1])
        sorted_map_2 = sorted(map_2.items(), key=lambda x:x[1])

        sorted_map_1_key = sorted(map_1.items(), key=lambda x:x[0])
        sorted_map_2_key = sorted(map_2.items(), key=lambda x:x[0])

        print(sorted_map_1)
        print(sorted_map_2)
        print(sorted_map_1_key)
        print(sorted_map_2_key)

        i=0
        for item in sorted_map_1_key:
            if item[0] != sorted_map_2_key[i][0]:
                return False
            i+=1
        i = 0
        for item in sorted_map_1:
            if item[1] != sorted_map_2[i][1]:
                return False
            i+=1
        

#//print(sorted_map_2)



        # print(map_1)

        return True