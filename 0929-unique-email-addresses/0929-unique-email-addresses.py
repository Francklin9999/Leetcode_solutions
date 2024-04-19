class Solution(object):
    def numUniqueEmails(self, emails):
        """
        :type emails: List[str]
        :rtype: int
        """
        newemails = set()
        for address in emails:
            x, y = address.split("@")
            x = (x.split("+")[0])
            x = x.replace(".", "")
            newemails.add((x,y))
            
        return(len(newemails))