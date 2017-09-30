#pragma once
#include "Scene.h"
#include "Save.h"

class SubMap : public Scene
{
private:
    SubMap();
public:
    SubMap(int num);
    virtual ~SubMap();

    int view_x_ = 0, view_y_ = 0;
    int16_t& man_x_, &man_y_;
    int man_pic_;
    int step_ = 0;

    const int COORD_COUNT = SUBMAP_COORD_COUNT;

    int const MAN_PIC_0 = 2501;            //��ʼ��������ͼƫ����
    int const MAN_PIC_COUNT = 7;           //��������ͼ����
    int scene_id_;   //������

    SubMapRecord* record_;

public:
    SubMapRecord* getRecord() { return record_; }

    void setSceneNum(int num) { scene_id_ = num; }

    void setPosition(int x, int y) { setManPosition(x, y); setViewPosition(x, y); }
    //ע���ӽǺ����ǵ�λ�ÿ��ܲ�һ��
    void setManPosition(int x, int y) { man_x_ = x; man_y_ = y; }
    void setViewPosition(int x, int y) { view_x_ = x; view_y_ = y; }

    virtual void draw() override;
    virtual void dealEvent(BP_Event& e) override;
    virtual void backRun() override;
    virtual void entrance() override;
    virtual void exit() override;

    void tryWalk(int x, int y, Towards t);

    bool checkEvent(int x, int y, Towards t = None, int item_id = -1);

    //��һ���¼�����������
    bool checkEvent1(int x, int y, Towards t) { return checkEvent(x, y, t, -1); }
    //�ڶ����¼�����Ʒ����
    bool checkEvent2(int x, int y, Towards t, int item_id) { return checkEvent(x, y, t, item_id); }
    //�������¼�����������
    bool checkEvent3(int x, int y) { return checkEvent(x, y, None, -1); }

    virtual bool isBuilding(int x, int y);
    virtual bool isOutLine(int x, int y);
    bool isWater(int x, int y);
    bool isCanPassEvent(int x, int y);
    bool isCannotPassEvent(int x, int y);
    bool isFall(int x, int y);
    bool isExit(int x, int y);

    virtual bool isOutScreen(int x, int y) override;
    virtual bool canWalk(int x, int y) override;

    void getMousePosition(int _x, int _y);

    Point getPositionOnWholeEarth(int x, int y);

};
