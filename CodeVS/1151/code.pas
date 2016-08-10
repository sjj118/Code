var
  n,m,i,k:longint;
  a,b:array[1..5000]of longint;

  procedure swap(var a,b:longint);
  var
    t:longint;
  begin
    t:=a;
	a:=b;
	b:=t;
  end;

  procedure qsort();
    procedure sort(l,r:longint);
	var
	  i,j,x,y:longint;
	begin
	  x:=b[(l+r)div 2];
	  y:=a[(l+r)div 2];
	  i:=l;
	  j:=r;
	  repeat
	    while (b[i]>x)or(b[i]=x)and(a[i]<y) do inc(i);
	    while (b[j]<x)or(b[j]=x)and(a[j]>y) do dec(j);
		if i<=j then begin
		  swap(a[i],a[j]);
		  swap(b[i],b[j]);
		  inc(i);
		  dec(j);
		end;
	  until i>j;
	  if i<r then sort(i,r);
	  if j>l then sort(l,j);
	end;
	
  begin
    sort(1,n);
  end;
begin
  readln(n,m);
  for i:=1 to n do readln(a[i],b[i]);
  qsort;
  i:=trunc(m*1.5);
  k:=b[i];
  while (b[i+1]=k)and(i<n) do inc(i);
  writeln(k,' ',i);
  for k:=1 to i do writeln(a[k],' ',b[k]);
end.
