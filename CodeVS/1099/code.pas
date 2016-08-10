type
	statetype=record
		height:longint;
		s:string;
	end;
var
	s1,s2,t:string;
	a,b:array[1..6]of string;
	i,j,k,l,head,tail,arr,len:longint;
	queue:array[0..99999]of statetype;
	state:statetype;
	flag:boolean;

	
	procedure sin(var a:string;var b:string);
	var
		s:string;
	begin
		readln(s);
		a:=copy(s,1,pos(' ',s)-1);
		b:=copy(s,pos(' ',s)+1,length(s)-pos(' ',s));
	end;

	procedure enter(newstate:statetype);
	begin
		tail:=(tail+1)mod 100000;
		queue[tail]:=newstate;
	end;
begin
	sin(s1,s2);
	len:=length(s1)+length(s2);
	arr:=1;
	for i:=1 to 6 do sin(a[i],b[i]);
	while (not flag)and(queue[head].height<=10) do begin
	inc(arr);
	state.height:=0;
	state.s:=s1;
	head:=0;
	tail:=-1;
	enter(state);
	while (head<=tail)and(queue[head].height<=10) do begin
		if queue[head].s=s2 then begin flag:=true; break; end;
		if queue[head].height<=10 then with queue[head] do begin
			for i:=1 to 6 do begin
				k:=pos(a[i],s);
				t:=s;
				j:=0;
				while k<>0 do begin
					state.s:=s;
					delete(state.s,k+j,length(a[i]));
					insert(b[i],state.s,k+j);
					if length(state.s)>len*arr then break;
					delete(t,k,1);
					inc(j);
					k:=pos(a[i],t);
					state.height:=height+1;
					enter(state);
				end;
			end;
		end;
		head:=(head+1)mod 100000;
	end;
	end;
	if flag then writeln(queue[head].height) else writeln('NO ANSWER!');
end.