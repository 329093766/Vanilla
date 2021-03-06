// Vanilla控件处理
#pragma once



#define VM_CREATE	1
#define VM_DESTROY	2
#define VM_SETFOCUS	3
#define VM_KILLFOCUS	4
#define VM_SETVISIBLE	5
#define VM_SETENABLED	6
#define VM_PAINT	7
#define VM_SIZE		8
#define VM_MOVE		9
#define VM_TIMER	10
#define VM_CHAR		11
#define VM_KEYDOWN	12
#define VM_KEYUP	13
#define VM_LBUTTONDOWN	14
#define VM_LBUTTONUP	15
#define VM_LBUTTONCLK	16
#define VM_LBUTTONDBCLK	17
#define VM_RBUTTONDOWN	18
#define VM_RBUTTONUP	19
#define VM_RBUTTONCLK	20
#define VM_RBUTTONDBCLK	21
#define VM_MBUTTONDOWN	101
#define VM_MBUTTONUP	102
#define VM_MBUTTONCLK	103
#define VM_MBUTTONDBCLK	104
#define VM_MOUSEWHEEL	22
#define VM_SETPARENT	24
#define VM_MOUSEMOVE	26
#define VM_MOUSEIN	27
#define VM_MOUSEOUT	28
#define VM_REDRAW	29
#define VM_UPDATE	30
#define VM_USER		301
#define VM_NOTIFY	999


#define VE_LBTNCLK	1	// 左键单击
#define VE_LBTNDOWN	2	// 左键按下
#define VE_LBTNUP	3	// 左键弹起
#define VE_LBTNDBCLK	4	// 左键双击
#define VE_RBTNCLK	5	// 右键单击
#define VE_RBTNDOWN	6	// 右键按下
#define VE_RBTNUP	7	// 右键弹起
#define VE_RBTNDBCLK	8	// 右键双击
#define VE_KEYDOWN	9	// 按下某键
#define VE_KEYUP	10	// 放开某键
#define VE_CHAR		11	// 字符输入
#define VE_MOUSEMOVE	12	// 鼠标移动
#define VE_MOUSEIN	13	// 鼠标进入
#define VE_MOUSELEAVE	14	// 鼠标离开
#define VE_MOUSEWHEEL	15	// 滚轮滚动
#define VE_MBTNCLK	16	// 中键单击
#define VE_MBTNDOWN	17	// 中键按下
#define VE_MBTNUP	18	// 中键弹起
#define VE_MBTNDBCLK	19	// 中键双击


typedef struct VControl
{
	VControl() {}
	// 链表 Begin
	// 同级控件
	VanillaControl LastControl;
	VanillaControl NextControl;
	// 子控件
	VanillaControl ChildControlFirst;
	VanillaControl ChildControlEnd;
	// 上级控件
	VanillaControl ParentControl;
	// 链表 End

	// 自定义ID
	VanillaInt ID;

	// 控件属性 Begin
	// 窗口
	VanillaWindow Window;
	// 可视
	VanillaBool Visible;
	// 可用
	VanillaBool Enabled;
	// 父层所有组件中不可用的层数
	VanillaInt DisabledCount;
	// 父层所有组件中不可视的层数
	VanillaInt InvisibleCount;
	// 鼠标穿透
	VanillaBool MousePenetration;
	// 透明度
	VanillaByte Alpha;
	// 控件回调函数(替换Class中的控件回调函数)
	VCtlProc CtlProc;
	// 事件回调函数
	VCtlEventProc EventProc;
	// 绑定控件 此控件可接收到NOTIFY消息
	VanillaControl BindOwner;
	// 控件类
	VanillaControlClass Class;

	VRect Rect;

	// 缓存图形
	VanillaGraphics Graphics;
	// 渐变缓存图形
	VanillaGraphics Graphics_Gradient1;
	VanillaGraphics Graphics_Gradient2;
	// 渐变参数
	VanillaBool Gradienting;
	VanillaReal GradientAlpha;
	VanillaInt GradientUserData;
	VanillaBool GradientType;
	// 控件属性 End

	VanillaAny ControlData;
} *VanillaControl, _VControl;

typedef struct VControlClass
{
	VanillaString ClassName;
	VCtlProc CtlProc;
	VanillaBool Focusable;
	VanillaBool Virtual;
} *VanillaControlClass, _VControlClass;


VAPI(VanillaControlClass) VanillaRegisterControlClass(VanillaText ClassName, VCtlProc CtlProc, VanillaBool Focusable, VanillaBool Virtual);
VAPI(VanillaControl) VanillaControlCreate(VanillaControl ParentControl, VanillaText ClassName, VanillaRect Rect, VanillaAny ControlData, VanillaInt CustomID, VanillaBool Visible, VanillaBool Enabled, VanillaAny CreateStruct);
VAPI(VanillaInt) VanillaControlDestroy(VanillaControl Control);
VAPI(VanillaInt) VanillaControlRedraw(VanillaControl Control, VanillaBool Update);
VAPI(VanillaVoid) VanillaControlSetEnable(VanillaControl Control, VanillaBool Enabled);
VAPI(VanillaBool) VanillaControlIsEnable(VanillaControl Control);
VAPI(VanillaVoid) VanillaControlSetVisible(VanillaControl Control, VanillaBool Visible);
VAPI(VanillaBool) VanillaControlIsVisible(VanillaControl Control);
VAPI(VanillaVoid) VanillaControlSetAlpha(VanillaControl Control, VanillaByte Alpha);
VAPI(VanillaByte) VanillaControlGetAlpha(VanillaControl Control);
VAPI(VanillaVoid) VanillaControlMove(VanillaControl Control, VanillaInt Left, VanillaInt Top, VanillaInt Width, VanillaInt Height);
VAPI(VanillaRect) VanillaControlGetRectOfWindow(VanillaControl Control, VanillaRect Rect);
VAPI(VanillaRect) VanillaControlGetRect(VanillaControl Control);
VAPI(VanillaVoid) VanillaControlSetEventProc(VanillaControl Control, VCtlEventProc EventProc);
VAPI(VCtlEventProc) VanillaControlGetEventProc(VanillaControl Control);
VAPI(VanillaVoid) VanillaControlSetDefaultEventProc(VCtlEventProc EventProc);
VAPI(VanillaInt) VanillaControlTriggerEvent(VanillaControl Control, VanillaInt Event, VanillaInt Param1, VanillaInt Param2, VanillaInt Param3);
VAPI(VanillaInt) VanillaControlSendMessage(VanillaControl Control, VanillaInt Message, VanillaInt Param1, VanillaInt Param2);
VAPI(VanillaVoid) VanillaControlSendMessageToChild(VanillaControl ParentControl, VanillaInt Message, VanillaInt Param1, VanillaInt Param2);
VAPI(VanillaVoid) VanillaControlSendMessageToChildOfWindow(VanillaWindow Window, VanillaInt Message, VanillaInt Param1, VanillaInt Param2);
VAPI(VanillaControl) VanillaFindControlInWindow(VanillaWindow Window, VanillaPoint pt, VanillaPoint pt2);
VAPI(VanillaControl) VanillaFindControlInControl(VanillaControl ParentControl, VanillaPoint pt, VanillaPoint pt2);

VanillaInt VanillaDefaultControlProc(VanillaControl Control, VanillaInt Message, VanillaInt Param1, VanillaInt Param2);

extern std::map<VanillaString, VanillaControlClass> ControlClasses;
