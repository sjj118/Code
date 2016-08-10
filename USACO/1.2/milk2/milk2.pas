{
ID: sjj22451
LANG: PASCAL
PROB:milk2
}
type
  list=array[1..5000]of longint;
var
  n,i,j,l1,l2,p1,p2:longint;
  a,b,c,d:list;
  flag:boolean;

  function max(a,b:longint):longint;
  begin
    if a>b then max:=a else max:=b;
  end;

  function min(a,b:longint):longint;
  begin
    if a<b then min:=a else min:=b;
  end;

  procedure swap(var a,b:longint);
  var
    t:longint;
  begin
    t:=a;
	a:=b;
	b:=t;
  end;

  procedure qsort(var a,b:list);

    procedure sort(l,r:longint);
	var
	  x,i,j,t:longint;
	begin
	  i:=l;
	  j:=r;
	  x:=a[(l+r)div 2];
	  repeat
	    while a[i]<x do inc(i);
	    while a[j]>x do dec(j);
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
  assign(input,'milk2.in');reset(input);
  assign(output,'milk2.out');rewrite(output);
  readln(n);
  for i:=1 to n do readln(a[i],b[i]);
  c:=a;d:=b;
  qsort(a,b);
  p1:=a[1];
  p2:=b[1];
  for i:=2 to n do begin
    if a[i]<=p2 then p2:=max(p2,b[i]) else begin l1:=max(l1,p2-p1); p1:=a[i]; p2:=b[i]; end;
  end;
  l1:=max(l1,p2-p1);
  write(l1,' ');
  qsort(d,c);
  l1:=0;
  for i:=1 to n-1 do begin
    flag:=false;
	for j:=1 to n do if (a[j]<=d[i])and(b[j]>d[i]) then begin flag:=true; break; end;
	if flag then continue;
    for j:=1 to n do if d[i]<=a[j] then begin l2:=a[j]-d[i]; break; end;
	l1:=max(l1,l2);
  end;
  writeln(l1);
  close(input);close(output);
end.
