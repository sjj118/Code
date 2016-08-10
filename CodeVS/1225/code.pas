const
	fact:array[0..8]of longint=(1,1,2,6,24,120,720,5040,40320);
	dir:array[1..4]of longint=(1,-1,3,-3);
type
	list=array[1..9]of char;
var
	i,tar,head,tail,now,x,ne:longint;
	s,next:list;
	h:array[0..362880]of longint;
	queue:array[1..362880]of list;
	
	function count(s:list):longint;
	var
		i,j,t:longint;
	begin
		count:=0;
		for i:=1 to 9 do begin
			t:=0;
			for j:=i+1 to 9 do if s[j]<s[i] then inc(t);
			count:=count+t*fact[9-i];
		end;
	end;
	
	function cantor(x:longint):list;
	var
		i,t:longint;
		j:char;
		find:array['0'..'8']of boolean;
	begin
		fillchar(find,sizeof(find),false);
		for i:=1 to 9 do begin
			t:=x div fact[9-i];
			x:=x-t*fact[9-i];
			for j:='0' to '8' do begin
				if not find[j] then begin
					if t=0 then begin
						find[j]:=true;
						cantor[i]:=j;
						break;
					end;
					dec(t);
				end;
			end;
		end;
	end;
	
	procedure put(s:string);
	begin
		inc(tail);
		queue[tail]:=s;
	end;
	
	procedure swap(var a,b:char);
	var
		t:char;
	begin
		t:=a;
		a:=b;
		b:=t;
	end;
begin
	readln(s);
	head:=1;
	tail:=0;
	tar:=count(s);
	s:='123804765';
	put(s);
	while tail>=head do begin
		s:=queue[head];
		now:=count(s);
		if now=tar then begin
			writeln(h[now]);
		end;
		for i:=1 to 9 do if s[i]='0' then begin x:=i; break; end;
		for i:=1 to 4 do begin
			if i=1 then begin
				if x mod 3=0 then continue;
			end else if i=2 then begin
				if x mod 3=1 then continue;
			end else if i=3 then begin
				if x>6 then continue;
			end else begin
				if x<=3 then continue;
			end;
			next:=s;
			swap(next[x],next[x+dir[i]]);
			ne:=count(next);
			if h[ne]=0 then begin
				h[ne]:=h[now]+1;
				put(next);
			end;
		end;
		inc(head);
	end;
end.