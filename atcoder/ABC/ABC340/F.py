x, y = map(int, input().split())

'''
二元一次不定方程式 ax+by=c(a≠0かつb≠0) を解く
初期化すると、x=x0+m*b,y=y0-m*aで一般解が求められる(m=0で初期化)
'''
from math import gcd
class LDE:
    #初期化
    def __init__(self,a,b,c):
        self.a,self.b,self.c=a,b,c
        self.m,self.x,self.y=0,[0],[0]
        #解が存在するか
        self.check=True
        g=gcd(self.a,self.b)
        if c%g!=0:
            self.check=False
        else:
            #ax+by=gの特殊解を求める
            self.extgcd(abs(self.a),abs(self.b),self.x,self.y)
            if a<0:self.x[0]=-self.x[0]
            if b<0:self.y[0]=-self.y[0]
            #ax+by=cの特殊解を求める
            self.x=self.x[0]*c//g
            self.y=self.y[0]*c//g
            #一般解を求めるために
            self.a//=g
            self.b//=g

    #拡張ユークリッドの互除法
    #返り値:aとbの最大公約数
    def extgcd(self,a,b,x0,y0):
        if b==0:
            x0[0],y0[0]=1,0
            return a
        d=self.extgcd(b,a%b,y0,x0)
        y0[0]-=(a//b)*x0[0]
        return d

    #パラメータmの更新(書き換え)
    def m_update(self,m):
        self.x+=(m-self.m)*self.b
        self.y-=(m-self.m)*self.a
        self.m=m

temp1 = LDE(-y,x,2)
temp2 = LDE(y,-x,2)
if (temp1.check == False) and (temp2.check == False):
    print(-1)
    exit()

if temp1:
    print(temp1.x)
    print(temp1.y)
    exit()

if temp2:
    print(temp2.x)
    print(temp2.y)
    exit()