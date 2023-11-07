n=10
ans=0
e=list()
for i in range(2...n):
    for j in range(1...i):
        if(j==1): ans+=e[i-1][j][j]
        elif(j==i): ans+=e[i-1][j-1][j]
        else: ans+=min(e[i-1][j-1][j],e[i-1][j][j])

dist=list()
V=list()
t1=0
t2=0
t3=0
def dijkstra(s):pass
dist[0]=dijkstra(t1)
dist[1]=dijkstra(t2)
dist[2]=dijkstra(t3)
for i in V:
    ans=min(ans,max(dist[0][i],dist[1][i],dist[2][i]))

def check(n,cost,work,k):
    vst=[False]*n
    total=0
    for i in range(0,n):
        if(vst[work[i]]): return False
        total+=cost[i][work[i]]
        vst[work[i]]=True
    return bool(total<k)

def P(a,b,c):
    a2=[]
    b2=[]
    for i in a:
        a2.append(1 if i>0 else 0)
    for i in b:
        b2.append(1 if i>0 else 0)
    return Q(a2,b2,c)

def Q(a,b,c):
    a2=[]
    b2=[]
    for i in a:
        a2.append(1 if 1<=i<=2 else 0)
    for i in b:
        b2.append(1 if 1<=i<=2 else 0)
    return P(a2,b2,c)