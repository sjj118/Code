var
  i,j,tm,tf,p1,t:longint;
  m:array[0..100001]of longint;
  f:array[0..100000]of char;
  s:ansistring;

  function getP(a:char):longint;
  begin
    if(a='+')then getP:=1 else getP:=2;
  end;

  procedure put(a:longint);
  begin
    inc(tm);
    m[tm]:=a mod 10000;
  end;

  procedure put(a:char);
  begin
    inc(tf);
    f[tf]:=a;
  end;

  function getm():longint;
  begin
    getm:=m[tm];
    dec(tm);
  end;

  function getf():char;
  begin
    getf:=f[tf];
    dec(tf);
  end;

begin
  readln(s);
  f[0]:='+';
  tm:=0;tf:=0;
  p1:=0;
  for i:=1 to length(s)+1 do begin
    if(i>length(s))or(s[i]='+')or(s[i]='*')then begin
      val(copy(s,p1+1,i-p1-1),t);
      put(t);
      p1:=i;
      if(i<=length(s))then begin
        while(getP(f[tf])>getP(s[i]))do begin
          getf;
          put(getm*getm);
        end;
        put(s[i]);
      end;
    end;
  end;
  while tf>0 do begin
    if(getf='+')then put(getm+getm) else put(getm*getm);
  end;
  writeln(getm);
end.
