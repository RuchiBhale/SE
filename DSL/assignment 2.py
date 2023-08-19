str=input("Enter the string: ")
class String_operations:
    def __init__(self,sent):
        self.sent=sent

    def longest(self):
        str1=self.sent+ " "
        wrd = ""
        length = 0
        max_str = ""
        for i in str1:
            if (i != ""):
                wrd = wrd + i
            if (i == " "):
                if (len(wrd) > length):
                    length = len(wrd)
                    max_str = wrd
                wrd = ""
        print("Longest string is: ", max_str)


    def occurence(self):
        freq=0
        ch=input("Enter the charcter whose frequency of occurence is to be checked:")
        for i in self.sent:
           if(ch==i):
               freq+=1
        print("The occurence of character is:",freq)


    def palindrome(self):
        rev=""
        for i in range((len(self.sent)-1),-1,-1):
            rev=rev+self.sent[i]
        if(self.sent==rev):
            print("Palindrome")


    def index(self):
        sub=input("Enter the subsrting: ")
        wrd1=""
        l=[]
        for i in range (len(sub)):
            for j in range(len(self.sent)):
                if(sub[i]==self.sent[j]):
                    wrd1=wrd1+self.sent[j]
                    l.append(j)
        print("The index of first occurence of substring is",l[0])




    def word_count(self):
        str1 = self.sent + " "
        word=[]
        distinct_words=[]
        str2=""
        count=0
        for i in str1:
            if(i==" "):
                word.append(str2)
                str2=""
            else:
                str2=str2+i
        for i in word:
            if i not in distinct_words:  # to make a list of distinct words
                distinct_words.append(i)
        for i in distinct_words:
            count=0
            for j in range(len(word)):
                if(i==word[j]):
                    count+=1
            print("The occurence of ", i, "is", count)



def main():
    x=String_operations(str)
    x.longest()
    x.occurence()
    x.palindrome()
    x.index()
    x.word_count()


if (__name__=="__main__"):
    main()
