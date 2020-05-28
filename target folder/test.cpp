 class test
{
private:
        bool state;
        int x;
        int i;
        int lastnum;
        int count;
public:
        test(x)
        {
                state = true;
                this.x = x;
                i = 0;
                count = 0;

        }
        bool getNum(y)
        {
                count++;
                if(!state) return;
                if(i % 2 == 0)
                {
                        if (lastnum == i*y) state = false;
                        lastnum = i*y;
                        i++;

                        return lastnum;
                }
                else
                { 
                        if (lastnum == i*x) state = false;
                        lastnum = i*x;
                        i++;
                        return lastnum;

                }
                
        }
        void reset()
        {
                state = true;
                i = 0;
        }
        int numReq()
        {
                return count;
        }

};