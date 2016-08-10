{
ID: sjj22451
LANG: PASCAL
PROB: barn1
}
type
  list=array[1..200]of longint;
var
  m,s,c,i,k:longint;
  a,b:list;
  
  procedure qsort(var a:list;n:longint);

    procedure sort(l,r: longint);
      var
         i,j,x,y: longint;
      begin
         i:=l;
         j:=r;
         x:=a[(l+r) div 2];
         repeat
           while a[i]<x do
            inc(i);
           while x<a[j] do
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
       sort(1,n);
    end;
begin
  assign(input,'barn1.in');reset(input);assign(output,'barn1.out');rewrite(output);
  readln(m,s,c);
  for i:=1 to c do begin
    readln(a[i]);
  end;
  qsort(a,c);
  for i:=1 to c-1do b[i]:=a[i+1]-a[i]-1;
  qsort(b,c-1);
  k:=c;
  for i:=1 to c-m do begin
    k:=k+b[i];
  end;
  writeln(k);
  close(input);close(output);
end.