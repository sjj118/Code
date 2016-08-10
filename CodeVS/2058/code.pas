var
  n,k,i,top:longint;
  s,stack:array[1..3000000]of char;
  c:char;

  procedure put(c:char);
  begin
    inc(top);
	stack[top]:=c;
  end;

  function get():char;
  begin
    if top>0 then get:=stack[top];
	dec(top);
  end;

  function go():boolean;
  begin
    while ord(s[i])<>0 do begin
	  if s[i] in ['(','{','[','<'] then put(s[i]);
	  if s[i] in [')','}',']','>'] then begin
	    c:=get;
		if (not (c in ['(','{','[','<']))or(c='(')and(s[i]<>')')or(c='{')and(s[i]<>'}')or(c='[')and(s[i]<>']')or(c='<')and(s[i]<>'>') then exit(false);
	  end;
	  inc(i);
	end;
	if top=0 then exit(true) else exit(false);
  end;
begin
  readln(n);
  for k:=1 to n do begin
    readln(s);
	top:=0;
	i:=1;
	writeln(go);
  end;
end.
