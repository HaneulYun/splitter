#pragma once

class CTearElement : public CVFXBase
{
	POINT* m_TargetPolygon;

	float m_OldDistance;
	float m_CurDistance;

	Vector m_OldPoint;
	float m_OldRatioX;
	float m_OldRatioY;
	float m_CurRatioX;
	float m_CurRatioY;

	float m_MyRotate;
	CTimer m_Timer;
public:
	CTearElement(Vector pt, int polyAngle, float distance, COLORREF color);
	~CTearElement();

	virtual bool Initialize() override;
	virtual void Terminate() override;
	virtual bool Pulse() override;
};