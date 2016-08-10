var
    n,l,j,k,head,tail:int64;
	i:longint;
    c:array[1..50000]of int64;
    sum:array[0..50000]of int64;
    f:array[0..50000]of int64;
    queue:array[1..50000]of int64;
 
    function getup(k,j:int64):int64;
    begin
        exit(f[j]+(j+sum[j]+k+sum[k])*(j+sum[j]-k-sum[k])-f[k]-2*k-2*k*l-2*sum[k]-2*sum[k]*l+2*j+2*j*l+2*sum[j]+2*sum[j]*l);
    end;
     
    function getdown(k,j:int64):int64;
    begin
        exit(2*j+2*sum[j]-2*k-2*sum[k]);
    end;
begin
    readln(n,l);
    for i:=1 to n do readln(c[i]);
    for i:=1 to n do sum[i]:=sum[i-1]+c[i];
    head:=1;
    tail:=1;
    queue[1]:=0;
    for i:=1 to n do begin
        while (tail>head)and(getup(queue[head],queue[head+1])<=(i+sum[i])*getdown(queue[head],queue[head+1])) do inc(head);
        f[i]:=f[queue[head]]+(i-queue[head]-1+sum[i]-sum[queue[head]]-l)*(i-queue[head]-1+sum[i]-sum[queue[head]]-l);
        while (tail>head)and(getup(queue[tail],i)*getdown(queue[tail-1],queue[tail])<getup(queue[tail-1],queue[tail])*getdown(queue[tail],i)) do dec(tail);
        inc(tail);
        queue[tail]:=i;
    end;
    writeln(f[n]);
end.