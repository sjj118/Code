var
  i,d,x,p,c,w,f,n:longint;
  s,t:string;
  xx:char;
begin
  readln(s);
  x:=1;
  if s[1] in ['+','-'] then p:=1 else p:=0;
  for i:=2 to length(s) do begin
    if s[i] in ['+','-','='] then begin
	  if s[p]='-' then f:=-1 else f:=1;
	  if s[i-1] in ['a'..'z'] then begin
	    xx:=s[i-1];
	    t:=copy(s,p+1,i-p-2);
	    val(t,n);
	    w:=w+x*f*n;
	  end else begin
	    t:=copy(s,p+1,i-p-1);
	    val(t,n);
	    c:=c-x*f*n;
	  end;
	  p:=i;
	end;
	if s[i]='=' then x:=-1;
  end;
  if s[p]='+' then f:=1 else f:=-1;
  t:=copy(s,p+1,i-p-1);
  val(t,n);
  if s[p]='-' then f:=-1 else f:=1;
  if s[length(s)] in ['a'..'z'] then begin
    xx:=s[length(s)];
	t:=copy(s,p+1,length(s)-p-1);
	val(t,n);
	w:=w+x*f*n;
  end else begin
	t:=copy(s,p+1,length(s)-p);
	val(t,n);
	c:=c-x*f*n;
  end;
  writeln(xx,'=',(c/w):0:3);
end.
