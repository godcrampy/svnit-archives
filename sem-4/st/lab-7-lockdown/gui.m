function varargout = gui(varargin)
% GUI MATLAB code for gui.fig
%      GUI, by itself, creates a new GUI or raises the existing
%      singleton*.
%
%      H = GUI returns the handle to a new GUI or the handle to
%      the existing singleton*.
%
%      GUI('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in GUI.M with the given input arguments.
%
%      GUI('Property','Value',...) creates a new GUI or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before gui_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to gui_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help gui

% Last Modified by GUIDE v2.5 02-May-2020 20:02:43

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @gui_OpeningFcn, ...
                   'gui_OutputFcn',  @gui_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT


% --- Executes just before gui is made visible.
function gui_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to gui (see VARARGIN)

% Choose default command line output for gui
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes gui wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = gui_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;


% --- Executes on button press in sine_button.
function sine_button_Callback(hObject, eventdata, handles)
% hObject    handle to sine_button (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
x0 = str2double(get(handles.x0_input, 'string'));
x1 = str2double(get(handles.x1_input, 'string'));
y0 = str2double(get(handles.y0_input, 'string'));
y1 = str2double(get(handles.y1_input, 'string'));
x = [x0:0.01:x1];
y = sin(x);
plot(x, y);
axis([x0 x1 y0 y1]);

% --- Executes on button press in pushbutton2.
function pushbutton2_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in cosine_button.
function cosine_button_Callback(hObject, eventdata, handles)
% hObject    handle to cosine_button (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
x0 = str2double(get(handles.x0_input, 'string'));
x1 = str2double(get(handles.x1_input, 'string'));
y0 = str2double(get(handles.y0_input, 'string'));
y1 = str2double(get(handles.y1_input, 'string'));
x = [x0:0.01:x1];
y = cos(x);
plot(x, y);
axis([x0 x1 y0 y1]);

% --- Executes on button press in cot_button.
function cot_button_Callback(hObject, eventdata, handles)
% hObject    handle to cot_button (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
x0 = str2double(get(handles.x0_input, 'string'));
x1 = str2double(get(handles.x1_input, 'string'));
y0 = str2double(get(handles.y0_input, 'string'));
y1 = str2double(get(handles.y1_input, 'string'));
x = [x0:0.01:x1];
y = cot(x);
plot(x, y);
axis([x0 x1 y0 y1]);


% --- Executes on button press in tan_button.
function tan_button_Callback(hObject, eventdata, handles)
% hObject    handle to tan_button (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
x0 = str2double(get(handles.x0_input, 'string'));
x1 = str2double(get(handles.x1_input, 'string'));
y0 = str2double(get(handles.y0_input, 'string'));
y1 = str2double(get(handles.y1_input, 'string'));
x = [x0:0.01:x1];
y = tan(x);
plot(x, y);
axis([x0 x1 y0 y1]);



% --- Executes on button press in cosec_button.
function cosec_button_Callback(hObject, eventdata, handles)
% hObject    handle to cosec_button (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
x0 = str2double(get(handles.x0_input, 'string'));
x1 = str2double(get(handles.x1_input, 'string'));
y0 = str2double(get(handles.y0_input, 'string'));
y1 = str2double(get(handles.y1_input, 'string'));
x = [x0:0.01:x1];
y = csc(x);
plot(x, y);
axis([x0 x1 y0 y1]);


% --- Executes on button press in sec_button.
function sec_button_Callback(hObject, eventdata, handles)
% hObject    handle to sec_button (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
x0 = str2double(get(handles.x0_input, 'string'));
x1 = str2double(get(handles.x1_input, 'string'));
y0 = str2double(get(handles.y0_input, 'string'));
y1 = str2double(get(handles.y1_input, 'string'));
x = [x0:0.01:x1];
y = sec(x);
plot(x, y);
axis([x0 x1 y0 y1]);



function x0_input_Callback(hObject, eventdata, handles)
% hObject    handle to x0_input (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of x0_input as text
%        str2double(get(hObject,'String')) returns contents of x0_input as a double


% --- Executes during object creation, after setting all properties.
function x0_input_CreateFcn(hObject, eventdata, handles)
% hObject    handle to x0_input (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end
