type
  big=record
    data:array[1..100]of byte;
	len:longint;
  end;
var
  n,i,j:longint;
  x:big;
  m:string;
  function change(a:char):longint;
  begin
    if (ord(a)>=ord('0'))and(ord(a)<=ord('9'))then change:=ord(a)-ord('0') else change:=ord(a)-ord('A')+10;
  end;
  
  function count(a:big):big;
  var
    i:longint;
  begin
    count:=a;
	for i:=1 to a.len do count.data[i]:=count.data[i]+a.data[a.len-i+1];
	for i:=1 to a.len do begin
	  count.data[i+1]:=count.data[i+1]+count.data[i] div n;
	  count.data[i]:=count.data[i]mod n;
	end;
	if count.data[count.len+1]>0 then count.len:=count.len+1;
  end;
  
  function hw(a:big):boolean;
  var
    i:longint;
  begin
    hw:=true;
    for i:=1 to a.len div 2 do if a.data[i]<>a.data[a.len-i+1] then exit(false);
  end;
  
  procedure init(a:big);
  begin
    a.len:=0;
	fillchar(a.data,sizeof(a.data),0);
  end;
begin
  readln(n);
  readln(m);
  init(x);
  x.len:=length(m);
  for i:=x.len downto 1 do x.data[i]:=change(m[x.len-i+1]);
  if hw(x) then begin writeln('STEP=0'); halt; end;
  for i:=1 to 30 do begin
    x:=count(x);
    if hw(x) then begin writeln('STEP=',i); halt; end;
  end;
  writeln('Impossible!');
end.