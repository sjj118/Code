type
  tlist=array[1..26]of int64;
var
  n,k,i,j:longint;
  c,m:int64;
  s:array[1..100000]of char;
  e:tlist;

  function min(a,b:int64):int64;
  begin
    if a<b then min:=a else min:=b;
  end;

  procedure qsort(var a : tlist);

    procedure sort(l,r: longint);
      var
         i,j,x,y: longint;
      begin
         i:=l;
         j:=r;
         x:=a[(l+r) div 2];
         repeat
           while a[i]>x do
            inc(i);
           while x>a[j] do
            dec(j);
           if not(i>j) then
             begin
                y:=a[i];
                a[i]:=a[j];
                a[j]:=y;
                inc(i);
                j:=j-1;
             end;
         until i>j;
         if l<j then
           sort(l,j);
         if i<r then
           sort(i,r);
      end;

    begin
       sort(1,26);
    end;
begin
  //assign(input,'code.in');reset(input);
  readln(n,k);
  read(s);
  for i:=1 to n do inc(e[ord(s[i])-ord('A')+1]);
  qsort(e);
  j:=0;
  c:=0;
  while k>0 do begin
    inc(j);
	m:=min(k,e[j]);
	dec(k,m);
	c:=c+m*m;
  end;
  write(c);
  close(input);
end.
