利用多元回归线性模型对boston房价预测



CRIM——该镇的人均犯罪率

ZN——占地面积超过25000平方米的住宅用地比例

INDUS——城镇中非住宅用地所占比例

CHAS——是否邻近Charies River

NOX——一氧化碳浓度

RM——每栋住宅的房间数

AGE——1940年以前建成的自住单位比例

DIS——距离5个波士顿的就业中心的加权距离

RAD——到径向公路的可达性指数

TAX——每一万美元的不动产税率

PTRATIO——城镇中教师学生比例

B——城镇中黑人的比例

LSTAT——地区中多少房东属于低收入人群

MEDV——同类房屋价格的中位数



数据集共13个特征，1个目标，506*14个数据，其中需要选取对MEDV有影响且影响比较大的特征进行数据拟合（模型建立），从而实现房价预测