type
	list=array[0..120]of longint;
var
	rest,s,i,j:longint;

    function min(a,b:longint):longint;
	begin
		if a<b then exit(a) else exit(b);
	end;
	
	function count(var len:longint):list;
	var
		s1,s2:list;
		i,j,s,l,l1,l2:longint;
	begin
		read(l,s);
		rest:=rest-l*2;
		for i:=0 to 120 do count[i]:=maxlongint div 3;
		if s=0 then begin
			s1:=count(l1);
			s2:=count(l2);
			for i:=0 to l1 do for j:=0 to l2 do count[i+j]:=min(count[i+j],s1[i]+s2[j]);
			len:=l1+l2;
			for i:=1 to len do if count[i]>rest then begin len:=i-1; break; end;
		end else begin
			len:=min(s,(rest-1)div 5);
			for i:=0 to len do count[i]:=5*i;
		end;
		for i:=1 to len do count[i]:=count[i]+l*2;
		rest:=rest+l*2;
	end;
begin
	readln(s);
	rest:=s;
	count(j);
	writeln(j);
end.
