type
	boardtype=array[0..5,0..5]of longint;
	position=record
		x,y:longint;
	end;
	statetype=record
		height:longint;
		from,tar:position;
		next:byte;
		board:boardtype;
	end;
const
	direction:array[1..2,1..4]of longint=((1,-1,0,0),(0,0,1,-1));
var
	state:statetype;
	i,j,k:longint;
	c:char;
	queue:array[1..100000]of statetype;
	head,tail:longint;

	function toposition(x,y:longint):position;
	begin
		toposition.x:=x;
		toposition.y:=y;
	end;
	
	procedure enter(s:statetype);
	begin
		inc(tail);
		queue[tail]:=s;
	end;
	
	function success(a:boardtype):boolean;
	var
		i,j:longint;
		flag:boolean;
	begin
		for i:=1 to 4 do begin
			flag:=true;
			for j:= 2 to 4 do flag:=flag and(a[i,j]=a[i,1]);
			if flag then exit(true);
		end;
		for j:=1 to 4 do begin
			flag:=true;
			for i:= 2 to 4 do flag:=flag and(a[i,j]=a[1,j]);
			if flag then exit(true);
		end;
		flag:=true;
		for i:=2 to 4 do flag:=flag and (a[i,i]=a[1,1]);
		if flag then exit(true);
		flag:=true;
		for i:=2 to 4 do flag:=flag and (a[i,5-i]=a[1,4]);
		if flag then exit(true);
		exit(false);
	end;
begin
	head:=1;tail:=0;
	with state do begin
		for i:=1 to 4 do begin
			for j:=1 to 4 do begin
				read(c);
				if c='B' then state.board[i,j]:=1;
				if c='W' then state.board[i,j]:=2;
				if c='O' then state.board[i,j]:=0;
			end;
			readln;
		end;
		height:=0;
		from:=toposition(0,0);
		tar:=toposition(0,0);
		next:=1;
		enter(state);
		next:=2;
		enter(state);
	end;
	while head<=tail do begin
		if success(queue[head].board) then break;
		with queue[head] do begin
			for i:=1 to 4 do begin
				for j:=1 to 4 do begin
					if board[i,j]=0 then begin
						for k:=1 to 4 do begin
							if not ((from.x=i)and(from.y=j) and (tar.x=i+direction[1,k])and(tar.y=j+direction[2,k])) then begin
								if board[i+direction[1,k],j+direction[2,k]]=next then begin
									state.height:=height+1;
									state.from:=toposition(i+direction[1,k],j+direction[2,k]);
									state.tar:=toposition(i,j);
									state.board:=board;
									state.board[state.from.x,state.from.y]:=0;
									state.board[state.tar.x,state.tar.y]:=next;
									state.next:=(next mod 2)+1;
									enter(state);
								end;
							end;
						end;
					end;
				end;
			end;
		end;
		inc(head);
	end;
	writeln(queue[head].height);
end.
